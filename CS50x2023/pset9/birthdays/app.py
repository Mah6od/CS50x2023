import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        message = ""
        inputname = request.form.get("name")
        inputmonth = request.form.get("month")
        inputday = request.form.get("day")
        if not inputname:
            message = "You didn't enter any name !"
        elif not inputday:
            message = "Birthday is missing from your input"
        elif not inputmonth:
            message = "You didn't enter birth month"
        else:
            db.execute(
                "INSERT INTO birthdays (name, month, day) VALUES(?, ?,?)",
                inputname,
                inputmonth,
                inputday,
            )
        birthdays = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", message=message, birthdays=birthdays)
    else:
        birthdays = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", birthdays=birthdays)


